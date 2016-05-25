# coding=utf-8
"""
用字典暴力破解ZIP压缩文件密码
"""

import zipfile
import threading
import optparse

def extractFile(zFile, password):
    try:
        zFile.extractall(pwd=password)
        print("Found Passwd:", password)
        return password
    except:
        pass

def main():
    parser = optparse.OptionParser('usage%prog -f <zipfile> -d <dictionary>')
    parser.add_option('-f', dest='zname',type='string',help='specify zip file')
    parser.add_option('-d', dest='dname',type='string',help='specify dictionary file')
    options, args = parser.parse_args()
    if options.zname == None | options.dname == None:
        print parser.usage
        exit(0)
    else:
        zname = options.zname
        dname = options.dname
    zFile = zipfile.ZipFile('unzip.zip')
    passFile = open('dictionary.txt')
    for line in passFile.readlines():
        password = line.strip('\n')
        t = threading.Thread(target=extractFile,args(zFile,password))
        t.start()
        """
        guess = extractFile(zFile, password)
        if guess:
            print('Password =', password)
            return
        else:
            print("can't find password")
            return
        """

if __name__ == '__main__':
    main()
