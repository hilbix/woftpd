> **DO NOT EXPOSE THIS TOOL TO THE PUBLIC INTERNET!**
>
> If you do, many funny random looking files will show up
> on your machine within seconds.
>
> However there should be no other bad sideffect except
> filling your precious disk with trainloads of bullshit
> in virtually no time.  But no gurantees, so you are
> fully self responsible if you ever let others
> access this tool if you do not fully trust them.


# woftpd

A truely minimal write only FTP deamon written in C

Features and limitations:

- chrooted implementation (read: forking)
- IPv4 only (for now)
- PASV mode only
- FTP is unencrypted
- As bug free as possible
- Extremely easy to use and versatile enough to be productive
- Truely minimal implementation
- FTP upload only (for example: networked printer+scanners)
- Each receive runs in it's own working directory
- Has a connect pool of 100 connects plus 1 connect per second
- Handles a backlog of 100 connects
- Expires inactivity within 60s
- Expires activivity within 1000s
- Lingers a maximum of 120s

Hence this should not eat more than 1441 sockets/processes in parallel,
even if DoSsed (something even a Raspberry PI can handle easily).


## Usage

	git clone https://github.com/hilbix/woftpd.git
	cd woftpd
	make
	sudo make install

Example use:

	sudo chmod 4711 /usr/local/sbin/woftpd; /usr/local/sbin/woftpd :21
	mkdir -m 1777 /var/tmp/ftp.incoming; echo 'ftp stream tcp nowait nobody /usr/local/sbin/woftpd :21 /var/tmp/ftp.incoming/' >> /etc/inetd.conf
	suid woftpd
	socklinger :21 woftpd -

Cmdline:

- 1: `-` for stdin or a socket to create and listen on
- 2 optional: A directory which must exist and be writeable
- 3+ optional: `cmd args..` executed with the filename received


## WTF why?

I got a printer+scanner combination which is able to do FTP.

It is able to do many things, however none worked out of the box:

- Send via file:  I do not have a Windows file service in place.
- Send via eMail: There is no local MTA
- Send via USB: far too difficult to handle
- Send via BT: No BT in reach
- Send via FTP: Where is a minimal FTP implementation?

There are big huge FTP implementations out there which can do plain everything.
They are extremely difficult to operate and configure,
you have to read trainloads of badly written documentation,
and all of them have a long and sad bad security history.

Long time ago there was TrollTechFTPd which I liked very much.
However even this beast is far too big to just so the job.
Also it was desinged to offer FTP read access,
something I do not need and cannot be switched off easily.

So I had to invent my own.  Something without any configuration
except just the bare minimum to be secure by default (except for
the protocol, as FTP is unencrypted) and which just does the job.

It also should fit in the usual usage scenarios like `inetd`.


# FAQ

License?

- Free as in free beer, free speech and free baby.

Why no tinolib?

- I want it to be minimal.
- This includes dependencies.

