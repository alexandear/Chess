import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import "Constants.js" as Constants

Rectangle {
    id: main
    anchors.fill: parent

    color: Constants.BACKGOUND_COLOR;

    RowLayout {
        id: root
        anchors.fill: parent
        spacing: 0

        Board {
            id: board
            objectName: "board"
            anchors.left: parent.left; anchors.top: parent.top; anchors.bottom: parent.bottom;
            anchors.margins: Constants.INDENT_DEFAULT
            width: height
        }

        ColumnLayout {

            anchors.left: board.right; anchors.right: parent.right;
            anchors.top: parent.top; anchors.bottom: parent.bottom
            anchors.margins: Constants.INDENT_DEFAULT
            spacing: Constants.INDENT_DEFAULT

            GameButton {
                id: startButton
                text: "Start"
                onClicked: {
                    loadButton.visible = !loadButton.visible
                    saveButton.visible = !saveButton.visible
                    board.clear()
                }
            }

            GameButton {
                id: loadButton
                text: "Load"
            }

            GameButton {
                id: saveButton
                text: "Save"
                visible: false
            }

        }

        states: [
            State {
                name: "screen_1"
            },
            State {
                name: "screen_2"
            },
            State {
                name: "screen_3"
            }
        ]
    }

}

