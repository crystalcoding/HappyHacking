import sys
import time
import datetime
import thread
import math

from PyQt4.QtGui import *
from PyQt4.QtCore import * #needed for signal

class ClockDlg(QDialog):
    TWENTY_FIVE_MINUTES_IN_SECOND = 25*60
    WORKING_STATE = True
    WORKING_STATE_LOCK = thread.allocate_lock()

    TOTAL_TOMATO = 0
    TOTAL_BREAK_TIME = 0
    def __init__(self,parent=None): #p118, pyqt4
        #call parent's constructor: p100, pyqt4
        super(ClockDlg, self).__init__(parent) 
        self.setWindowTitle("Pomodoro Timer")
        self.resize(100,100) #build-in method       
        
        self.startTimeLabel = QLabel('Start: ')
        self.endTimeLabel = QLabel('End:')
        self.breakTimeLabel = QLabel()
        self.messageLabel = QLabel("none")
        self.startButton = QPushButton("Start")
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.startButton)
        self.layout.addWidget(self.startTimeLabel)
        self.layout.addWidget(self.endTimeLabel)
        self.layout.addWidget(self.messageLabel)
        self.layout.addWidget(self.breakTimeLabel)

        self.setLayout(self.layout)
        

        #python does not detect signal error!e.g "click()" won't throw error
        self.connect(self.startButton, SIGNAL("clicked()"), 
                     self.updateTimer) #don't need to call self?

        #PyQt short-circuit cignal P.131 PyQT4
        #Note that we don't implement SCsignal, since all it do is call
        #the slot(by "emit" SCsignal) to which is it connected, "self.SCslot", in the case
        #AoQT programming, p.77
        self.connect(self, SIGNAL("SCsignal"), self.SCslot)
        self.connect(self, SIGNAL("BreakTimerStart"), self.breakCount)

    def updateTimer(self):
        ClockDlg.WORKING_STATE_LOCK.acquire()
        print "updateTime ClockDlg acquire lock?"
        ClockDlg.WORKING_STATE = True
        self.breakTimeLabel.setText('')
        ClockDlg.WORKING_STATE_LOCK.release()

        self.startTimeLabel.setText('Start: '+str(datetime.datetime.now()))
        startTime = datetime.datetime.now()
        self.startButton.setDisabled(True)
        self.startButton.setText('Working on this Pomodoro...')
        #p.356, python phrasebook
        thread.start_new_thread(self.setLabelText, (1,startTime))

    def setLabelText(self, delay, startTime):
        timeRemain = ClockDlg.TWENTY_FIVE_MINUTES_IN_SECOND
        while True:
            self.endTimeLabel.setText('End: '+str(datetime.datetime.now()))
            #different = datetime.datetime.now() - startTime
            #self.messageLabel.setText(str(different.seconds))
            print 'set new text for remaining time (setLabelTex)'
            self.messageLabel.setText('Time Remaining: '+str(timeRemain))
            timeRemain -= 1
            if timeRemain == 0:
                self.emit(SIGNAL("SCsignal")) #fire a signal from self
                self.startButton.setDisabled(False)
                self.startButton.setText('Start')
                break
            time.sleep(delay)
        
        self.emit(SIGNAL("BreakTimerStart"))

    def SCslot(self):
        #MUST call show() for the widget to be visible again
        #http://doc.trolltech.com/4.5/qt.html#WindowType-enum
        #Qt::WindowFlags e.g. Qt.SplashScreen
        #self.setWindowFlags(Qt.SplashScreen)
        #self.show()
        ClockDlg.TOTAL_TOMATO += 1
        completeMessage = '<center><font color="red">Pomodoro( '\
                           +str(ClockDlg.TOTAL_TOMATO)\
                           +' )Completed!</font></center>'
        print completeMessage
        self.messageLabel.setText(completeMessage)


    def breakCount(self):
        print "debug:break count thread "
        print "breakCount acquire lock"
        ClockDlg.WORKING_STATE_LOCK.acquire()
        ClockDlg.WORKING_STATE = False
        print 'breakCount, set CLockDlg.WORKING_STATE'
        ClockDlg.WORKING_STATE_LOCK.release()
        print 'breakCOunt release lock'

        breakID = thread.start_new_thread(self.incrementBreakTime, (1,))
        print "breakID", breakID

    def incrementBreakTime(self, delay):
        breakTime = 0
        while True:
            print "incrementBreakTIme"
            print "delay: ", delay
            ClockDlg.TOTAL_BREAK_TIME +=1
            breakTime += 1
            breakTimeMinute = math.floor(float(breakTime/60.0))
            breakTimeStat = 'Break Time:'+str(breakTime)\
                              +" ("+str(breakTimeMinute)+"Min)"
            ClockDlg.WORKING_STATE_LOCK.acquire()
            print 'acquire lock in increment break time'
            if ClockDlg.WORKING_STATE == False:
                ClockDlg.WORKING_STATE_LOCK.release()
                print 'release lock in increment break time'
                #BUG: need a lock for messageLabel
                #self.messageLabel.setText(str(breakTimeStat))
                self.breakTimeLabel.setText(str(breakTimeStat))
                print 'set new text for break time'
                time.sleep(delay)
            else:
                print 'release lock in break time in else'
                ClockDlg.WORKING_STATE_LOCK.release()
                break



if __name__ == "__main__":
    app = QApplication(sys.argv) #must have this

    clock = ClockDlg() #create a sub-class of QDialog object
    clock.show() #make it visible

    app.exec_() #enter event loop
