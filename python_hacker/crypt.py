#coding=utf-8
#!/usr/bin/env python

import crypt

def testPass(cryptPass):
    salt = cryptPass[0:2]
    dictfile = open('dictionary.txt','r')
    for word in dictfile.readlines():
        word = word.strip('\n')
        cryptWord = crypt.crypt(word,salt)
        if cryptPass == cryptWord:
            print "Found passed:" % word
            return
    print "password not found!"
    return

def main():
    passfile = open('passwords.txt','r')
    for line in passfile.readlines():
        user = line.split(':')[0]
        cryptPass = line.split(":")[1].strip('')
        print "cracking password for :" % user
        testPass(cryptPass)

if __name__ == '__main__':
    main()

