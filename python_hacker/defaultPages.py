# coding = UTF-8

import ftplib

def returnDefault(ftp):
    try:
        dirList = ftp.nlst()
    except:
        dirList = []
        print '[-] Could not list directory contents.'
        print '[-] Skipping To Next Target.'
        return
    retList = []
    for fileName in dirList:
        fn = fileName.lower()
        if '.php' in fn or '.htm' in fn or '.asp' in fn:
            print '[+] Found default page:' + fileName
            retList.append(fileName)
            return retList

host = 'dev.huangjinqianbao.com'
userName = 'vsftp'
passWord = 'vsftp'
ftp = ftplib.FTP()
ftp.connect(host,2121)
ftp.login(userName, passWord)
returnDefault(ftp)
