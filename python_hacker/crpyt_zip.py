# coding=utf-8
"""
用字典暴力破解ZIP压缩文件密码
"""

import zipfile
import threading

def extractFile(zFile, password):
    try:
        zFile.extractall(pwd=password)
        print("Found Passwd:", password)
        return password
    except:
        pass

def main():
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
