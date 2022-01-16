import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.12
import Shapes 1.0

Window {
    id: gameWindow
    width: 640
    height: 480
    visible: true
    color: "#FDFBFB"

    onAfterRendering: {
        startWindow.hide()
    }

    /*Timer {
        interval: 2000
        running: true
        onTriggered: ellipse1.color = "#FD8D12"
    }*/

    Grid {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        columns: 4
        rows: 4

        Repeater {
            id: repeater
            model: 16

            Flipable {
                property bool flipped: false
                width: 100
                height: 100

                transform: Rotation {
                    axis.x: 1; axis.y: 0; axis.z: 0
                    origin.x: repeater.itemAt(model.index).width / 2; origin.y: repeater.itemAt(model.index).height / 2
                    angle: repeater.itemAt(model.index).flipped ? 180 : 0

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
                        source: "qrc:/images/" + Math.ceil(Math.random() * 8) + ".svg"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        repeater.itemAt(model.index).flipped = !repeater.itemAt(model.index).flipped
                        console.log(model.index)
                    }
                }
            }
        }
    }
}
