import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.12
import Shapes 1.0

//Window {
//    id: gameWindow
//    width: 640
//    height: 480
//    visible: true
//    color: "#FDFBFB"

//    onAfterRendering: {
//        startWindow.hide()
//    }

    GridView {
        required model
        width: 400; height: 400
        cellWidth: 100; cellHeight: 100

        Component {
            id: tileDelegate

            Flipable {
                property bool flipped: false
                required property string zrodlo
                required property string name
                id: tile
                width: 100
                height: 100

                transform: Rotation {
                    axis.x: 1; axis.y: 0; axis.z: 0
                    origin.x: tile.width / 2; origin.y: tile.height / 2
                    angle: tile.flipped ? 180 : 0

                    Behavior on angle {
                        NumberAnimation { duration: 500 }
                    }
                }

                front: Ellipse {
                    anchors.fill: parent
                    anchors.margins: 0
                    color: "#273748"
                }

                back: Ellipse {
                    anchors.fill: parent
                    anchors.margins: 0
                    color: "#FD8D12"

                    Image {
                        anchors.margins: 0
                        x: parent.x + 20
                        y: parent.y + 20
                        height: 50
                        width: 50
                        source: zrodlo
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        tile.flipped = !tile.flipped
                        //                    console.log(tile.flipped)
                    }
                }
            }
        }

        delegate: tileDelegate
    }
//   }
