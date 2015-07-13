import QtQuick 2.0

import "Constants.js" as Constants

Item {
    id: root

    property int cellSize: 0
    property string letter: " "
    property bool whiteSide: false
    property int pieceIndex: -1

    width: cellSize
    height: cellSize

    MouseArea {
        id: mouseArea

        width: root.width
        height: root.height

        anchors.centerIn: parent

        enabled: letter !== " "

        drag.target: tile

        onPressed: console.log("Pressed:" + index)
        onReleased: {
            parent = (tile.Drag.target !== null) ? tile.Drag.target : root
        }

        Item {
            id: tile

            width: root.width
            height: root.height

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x: root.width / 2
            Drag.hotSpot.y: root.height / 2

            Text {
                id: text
                anchors.fill: parent
                color: whiteSide ? Constants.SIDE_WHITE : Constants.SIDE_BLACK
                font.family: chessFont.name
                font.pixelSize: 0.85 * root.width
                text: letter.toLowerCase()
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                Text {
                    anchors.fill: parent
                    color: Constants.SIDE_BLACK
                    font.family: parent.font.family
                    font.pixelSize: parent.font.pixelSize
                    text: letter
                    horizontalAlignment: parent.horizontalAlignment
                    verticalAlignment: parent.verticalAlignment

                }

            }

            states: State {
                when: mouseArea.drag.active
                ParentChange { target: tile; parent: root }
                AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
            }
        }

    }


}

