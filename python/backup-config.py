import os
import sys
import shutil
import datetime
import subprocess

def check_files(paths):
    #make sure the file path is good
    for p in paths:
        if os.path.exists(p) == False:
            error = p+ " does not exists, backup stopped"
            sys.exit(error)

def load_config():
    #where to copy from: a list of full paths
    configlist = ["/home/bps/.emacs",\
                  "/home/bps/.profile",\
                  "/home/bps/.xinitrc",\
                  "/usr/src/sys/amd64/conf/MYKERNEL",\
                  "/etc/fstab",\
                  "/usr/local/etc/apache22/httpd.conf",\
                  "/usr/local/etc/PolicyKit/PolicyKit.conf",\
                  "/boot/loader.conf",\
                  "/etc/make.conf",\
                  "/etc/rc.conf",\
                  "/etc/resolv.conf",\
                  "/etc/namedb/named.conf",\
                  "/etc/namedb/rndc.conf",\
                  "/etc/dhclient-enter-hooks",\
                  "/etc/ssh/sshd_config",\
                  "/etc/ipf.rules",\
                  "/etc/wpa_supplicant.conf",\
                  "/etc/X11/xorg.conf"]
    check_files(configlist)
    #where to copy to (directory)
    dest = ""
    if len(dest) == 0:
        now = datetime.datetime.now()
        current_time = str(now.year) + "-" +\
                       str(now.month) + "-" +\
                       str(now.day) 
        dest = os.getcwd()+ "/" + "config_backup-"+ current_time  
        os.mkdir(dest)
    #compress it or not
    compress_backup = 0
    return configlist, dest, compress_backup

def backup(config_list, dest, compress):
    for config_file in config_list:
        shutil.copy(config_file, dest)

def readme(config_list, dest):
    f=open(dest+"/README.txt", "w")
    #record where we backup
    print "backing up configuration files..."
    for path in config_list:
        f.write(path+"\n")
        print path
    #record dmesg
    f.write("------dmesg------\n")
    #f.write(str(os.system("dmesg"))), it prints to stdin
    #use subprocess to print in our descriptor (f)
    subprocess.Popen("dmesg", stdout=f) 
    f.close()

if __name__ == "__main__":
    config_files, dest, isCompressed = load_config()
    backup(config_files, dest, isCompressed)
    readme(config_files, dest)
    #what to do about hidden file? e.g. .emacs
