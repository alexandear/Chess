import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item
    width: 640
    height: 480

    ColumnLayout {
        id: columnLayout1
        x: 143
        y: 174
        width: 100
        height: 100

        Button {
            id: button1
            text: qsTr("Button")
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            anchors.fill: parent
        }
    }
    states: [
        State {
            name: "State1"
        }
    ]

}
