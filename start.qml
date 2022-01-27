import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts 1.15
import QtQuick.Window 2.12

Window {
    id: startWindow
    width: 640
    height: 480
    visible: true
    title: "MemoryGame"
    color: "#FDFBFB"

    Loader {
        id: game
        visible: false
        source: visible ? "/game.qml" : ""
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 50
        text: "Memory Game"
    }

    ColumnLayout {
        width: 200
        height: 100
        x: startWindow.width / 2 - 50
        y: startWindow.height / 2 - 50

        Button {
            id: startButton
            text: "START"
            onClicked: {
                game.visible = true
            }

            background: Rectangle {
                id: rect
                color: startButton.pressed ? "#D7DFE8" : "#F0A63F"
                radius: 50
                width: 100
                height: 40
            }
            contentItem: Text {
                font.pointSize: 20
                text: startButton.text
                color: startButton.pressed ? "#26303B" : "#FFFFFF"
                anchors.centerIn: rect
            }
        }

        Button {
            id: exitButton
            text: "WYJŚCIE"
            onClicked: {
                startWindow.close()
            }

            background: Rectangle {
                id: rect2
                color: exitButton.pressed ? "#D7DFE8" : "#F0A63F"
                radius: 50
                width: 100
                height: 40
            }
            contentItem: Text {
                font.pointSize: 20
                text: exitButton.text
                color: exitButton.pressed ? "#26303B" : "#FFFFFF"
                anchors.centerIn: rect2
            }
        }
    }
}
