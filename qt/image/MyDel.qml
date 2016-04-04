import QtQuick 2.0

import QtQuick.Window 2.0

import QtQuick.XmlListModel 2.0

Item {
    width: Screen.width/2
    height: Screen.height/10

//    Rectangle {
//        id: baseRec
//        width: Screen.width/2
 //       height: Screen.height/10
 //       color: c
 //   }

    Flow {
    Text {
        text: name

    }
    Text {
        text: p

    }
    }
}


