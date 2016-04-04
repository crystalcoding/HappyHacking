import QtQuick 2.3

Rectangle {
    //property alias mouseArea: mouseArea

    id: rootRct
    width: 360
    height: 360

    color: "red"

    MyButton {
        width: rootRct.width/2
        height: rootRct.height/3

        borderColor: "green"
        backColor: "blue"
        borderWidth: 4
        radius: 3

        text: "my custom button"
        textColor: "black"
        fontSize: rootRct.height/10
        hoverEnabled: true

        onButtonClicked: console.log("hello from a singal aka Go!")
        //onButtonClicked: console.log("hello from a single aka Go!")

    }

    Rectangle {
        id: rectangle2
        x: 80
        y: 140
        width: 122
        height: 200
        color: "#1e1818"

        Rectangle {
            id: rectangle1
            x: 40
            y: 19
            width: 38
            height: 48
            color: "#870f0f"
            radius: 18
        }

        Rectangle {
            id: rectangle3
            x: 40
            y: 76
            width: 38
            height: 48
            color: "#b7ae11"
            radius: 18
        }

        Rectangle {
            id: rectangle4
            x: 40
            y: 135
            width: 38
            height: 48
            color: "#158640"
            radius: 18
        }
    }
}
