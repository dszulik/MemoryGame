import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts 1.15
import QtQuick.Window 2.12
import Shapes 1.0

Window{
    id: gameWindow
    width: 640
    height: 640
    visible: true
    property alias model : gridView.model

    Connections {
        target: _gameLogic
        function onPointsChanged(xd) { pointy.text = xd }
        function onWin() { popupItem.open() }
    }

    Popup {
        id: popupItem
        x: gameWindow.width / 2 - this.width / 2
        y: gameWindow.height / 2 - this.height / 2
        width: 256
        height: 128
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        background: Rectangle {
            color: "#F0A53E"
            radius: 12
        }

        ColumnLayout {
            anchors.fill: parent

            Text {
                Layout.alignment: Qt.AlignCenter
                font.bold: true
                font.family: "Helvetica"
                font.pointSize: 24
                text: qsTr("Wygrałeś")
                color: "white"
            }

            Button {
                id: playAgain

                Layout.alignment: Qt.AlignCenter

                background: Rectangle {
                    color: "#C0CDD9"
                    implicitHeight: 40
                    implicitWidth: 140
                    radius: 22
                }

                contentItem: Text {
                    color: "#1C2837"
                    font.bold: true
                    font.family: "Helvetica"
                    font.pointSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    text: qsTr("Zagraj ponownie")
                    verticalAlignment: Text.AlignVCenter
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _gameLogic.restart(model)
                        pointsText = "0"
                        popupItem.close()
                    }
                }
            }
        }
    }

    Item {
        x: 32
        y: 24
        width: 578
        height: 48

        RowLayout {
            spacing: 16

            Text {
                id: logo
                text: qsTr("<b>memory</b>")
                font.family: "Helvetica"
                font.pointSize: 32
                color: "#1C2837"
                //                color: "#374759"
            }

            Item {
                width: 160
            }

            Button {
                id: restart
                text: qsTr("Restart")

                Layout.alignment: Qt.AlignCenter

                background: Rectangle {
                    color: "#F0A53E"
                    implicitHeight: 48
                    implicitWidth: 112
                    radius: 22
                }

                contentItem: Text {
                    color: parent.down ? "#1a1a1a" : "#ffffff"
                    font.bold: true
                    font.family: "Helvetica"
                    font.pointSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    text: parent.text
                    verticalAlignment: Text.AlignVCenter
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _gameLogic.restart(model)
                        pointsText = "0"
                    }
                }
            }

            Button {
                id: exit

                Layout.alignment: Qt.AlignCenter

                background: Rectangle {
                    color: "#C0CDD9"
                    implicitHeight: 48
                    implicitWidth: 128
                    radius: 22
                }

                contentItem: Text {
                    color: parent.down ? "#1a1a1a" : "#1C2837"
                    font.bold: true
                    font.family: "Helvetica"
                    font.pointSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    text: qsTr("Wyjście")
                    verticalAlignment: Text.AlignVCenter
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        gameWindow.close()
                    }
                }
            }
        }
    }

    GridView {
        required model
        width: 400; height: 400
        cellWidth: 100; cellHeight: 100
        id: gridView
        delegate: tileDelegate

        x: 124
        y: 124

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

    Rectangle {
        x: 238
        y: 540
        width: 160
        height: 60
        color: "#F0A53E"
        radius: 12

        ColumnLayout {
            x: 12
            y: 8
            spacing: 4

            Text {
                id: pointsText
                text: qsTr("Zdobyte punkty")
                font.family: "Helvetica"
                font.pointSize: 16
                color: "white"
            }

            Text {
                id: pointy
                text: qsTr("0")
                font.family: "Helvetica"
                font.pointSize: 16
                font.bold: true
                color: "white"

            }
        }
    }
}
