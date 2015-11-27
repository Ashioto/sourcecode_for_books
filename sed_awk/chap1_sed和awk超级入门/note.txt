[laputa@localhost chap1_sed和awk超级入门]$ awk '
BEGIN{
FS=":"
}
{shell[$NF]++}
END{
for (i in shell)
print i ":" shell[i];
}' /etc/passwd
/bin/sync:1
/bin/bash:2
/sbin/nologin:41
/sbin/halt:1
/sbin/shutdown:1

