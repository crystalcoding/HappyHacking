from os import listdir, sep
from sys import argv

def check_empty(dir):
    directory = []
    directory = listdir(dir)
    empty_directory = []  
    empty_directory = [x for x in directory if len(listdir(dir+sep+x)) == 0 ]
    print 'Missing Templates'
    print '================='
    for y in empty_directory:
        print y
    print '================='
    print 'Total Templates:', len(directory)
    print "Total Missing Template:", len(empty_directory)


def main():
    path = argv[1]
    check_empty(path)

if __name__ == '__main__':
    main()
