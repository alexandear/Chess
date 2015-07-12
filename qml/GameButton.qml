import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

import "Constants.js" as Constants

Button {
    property string text
    anchors.left: parent.left; anchors.right: parent.right;
    text: text
    style: ButtonStyle {
        background: Rectangle {
            radius: Constants.BUTTON_RADIUS
            color: control.pressed ? Constants.BUTTON_PRESSED_COLOR : Constants.BUTTON_COLOR
        }
        label: Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: Constants.BUTTON_FONT_FAMILY
            font.pointSize: Constants.BUTTON_FONT_SIZE
            color: Constants.BUTTON_TEXT_COLOR
            text: control.text
        }
    }
}
