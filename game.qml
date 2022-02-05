import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.12
import Shapes 1.0

Item {
    id: gameWindow
    width: 640
    height: 480
    visible: true
    property alias model : gridView.model

    Connections {
        target: _gameLogic
        function onPointsChanged(xd) { pointy.text = "Zdobyte punkty: " + xd }
    }

    Text {
        id: pointy
        text: "Zdobyte punkty: 0"
    }

    GridView {
        required model
        width: 400; height: 400
        cellWidth: 100; cellHeight: 100
        id: gridView
        delegate: tileDelegate

        Component {
            id: tileDelegate

            Flipable
            {
//                property bool flipped_flipped
                required property string name
                required property string zrodlo
                required property bool flipped
                required property string colFront
                required property string colBack

                id: tile
                width: 100
                height: 100

//                Connections {
//                    target: _model[name]
//                    function onFlippedChanged(flip) { tile.flipped_flipped = flip }
//                }

                transform: Rotation {
                    axis.x: 1; axis.y: 0; axis.z: 0
                    origin.x: tile.width / 2; origin.y: tile.height / 2
//                    angle: flipped_flipped ? 180 : 0
                    angle: flipped ? 180 : 0

                    Behavior on angle {
                        NumberAnimation { duration: 500 }
                    }
                }

                front: Ellipse {
                    anchors.fill: parent
                    anchors.margins: 0
                    color: colFront
                }

                back: Ellipse {
                    anchors.fill: parent
                    anchors.margins: 0
                    color: colBack

                    Image {
                        anchors.margins: 0
                        x: parent.x + 25
                        y: parent.y + 25
                        height: 40
                        width: 40
                        source: zrodlo
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked:
                    {
                        _model[name].setFlipped(this)
                        _gameLogic.checkVisibility(model)
                    }
                }
            }
        }
    }
}
