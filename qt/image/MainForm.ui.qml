import QtQuick 2.3

import QtQuick.Window 2.0

Rectangle {
    width: Screen.width/2
    height: Screen.height/2

    ListView {
        width: Screen.width/2
        height: Screen.height/2

        //model: mod
        model: xmlListModel

        delegate: MyDel {}
    }


    //MyModel {id: mod}

    XmlListModel {
        id: xmlListModel
        source: "http://thetvdb.com/api/GetSeries.php?seriesname=star%20trek"
        query: "/Data/Series"

        XmlRole {name: "banner"; query:"banner/string()"}
    }
}
