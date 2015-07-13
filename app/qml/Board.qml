import QtQuick 2.4

import "Constants.js" as Constants

Item {
    id: root

    property int cellSize: width / Constants.BOARD_SIZE
    property int moveFromIndex: -1
    property int moveToIndex: -1

    height: parent.width
    width: height

    function clear() {
        for (var i = 0; i < Constants.BOARD_SIZE * Constants.BOARD_SIZE; ++i) {
            pieceRepeater.itemAt(i).letter = ""
        }
    }

    function isWhiteSide(index) {
        var letter = getLetter(index);
        return letter === letter.toUpperCase();
    }

    function getLetter(index) {
        var letter = game.pieces[index];
        var res = letter;
        if (letter === 'b') {
            res = 'l';
        } else if (letter === 'B') {
            res = 'L';
        }
        return res;
    }

    FontLoader {
        id: chessFont;
        source: "qrc:/fonts/" + Constants.CHESS_FONT
    }

    Grid {
        id: cellGrid

        property int cellSize: parent.cellSize
        property Piece selectedPiece: null

        anchors.fill: parent
        rows: Constants.BOARD_SIZE
        columns: Constants.BOARD_SIZE

        Repeater {

            id: repeater

            model: Constants.BOARD_SIZE * Constants.BOARD_SIZE

            DropArea {
                id: dropArea

                width: cellGrid.cellSize
                height: width

                onDropped: console.log("dropped")
                onEntered: console.log("entered")

                Rectangle {
                    id: cell

                    anchors.fill: parent
                    border.width: Constants.BOARD_BORDER_WIDTH
                    border.color: Constants.BOARD_BORDER_COLOR

                    color: (Math.floor(index / Constants.BOARD_SIZE)
                        + (index % Constants.BOARD_SIZE)) % 2
                            ? Constants.CELL_DARK_COLOR : Constants.CELL_LIGHT_COLOR

                    states: [
                        State {
                            when: dropArea.containsDrag
                            PropertyChanges {
                                target: cell
                                color: "grey"
                            }
                        }
                    ]

                }
            }

        }

    }

    Grid {
        id: piecesGrid

        anchors.fill: parent
        rows: Constants.BOARD_SIZE
        columns: Constants.BOARD_SIZE

        Repeater {
            id: pieceRepeater

            model: Constants.BOARD_SIZE * Constants.BOARD_SIZE

            Piece {
                id: piece

                cellSize: cellGrid.cellSize
                whiteSide: isWhiteSide(index)
                letter: getLetter(index)
                pieceIndex: index
            }

        }

    }

}

