import QtQuick 2.4

import "Constants.js" as Constants

Item {
    id: root

    property int cellSize: width / Constants.BOARD_SIZE
    property int moveFromIndex: -1
    property int moveToIndex: -1

    height: parent.width
    width: height

    Grid {
        id: boardGrid

        anchors.fill: parent;
        property int cellSize: parent.cellSize;
        rows: Constants.BOARD_SIZE
        columns: Constants.BOARD_SIZE

        Repeater {
            id: repeater

            model: Constants.BOARD_SIZE*Constants.BOARD_SIZE
            Item {
                id: item

                width: root.cellSize;
                height: root.cellSize;

                function getCellColor() {
                    var determineColor = function (even) {
                        return (index % 2 === even)
                            ? Constants.CELL_DARK_COLOR : Constants.CELL_LIGHT_COLOR;
                    };
                    var normalColor = ((Math.floor(index / Constants.BOARD_SIZE) % 2) === 0)
                            ? determineColor(1) : determineColor(0);
                    return (root.moveFromIndex == index)
                        ? Constants.CELL_CHOOSE_COLOR : normalColor
                }

                Rectangle {
                    id: cell

                    anchors.fill: parent
                    border.width: Constants.BOARD_BORDER_WIDTH
                    border.color: Constants.BOARD_BORDER_COLOR
                    color: item.getCellColor()
                }

                //transparent item for mouse handle
                Item {
                    anchors.fill: parent
                    z: 5
                    MouseArea {
                        id: mouseSquareArea
                        anchors.fill: parent
                        hoverEnabled: true
                        onExited: cell.color = item.getCellColor()
                    }

                }

            }

        }

    }

}

