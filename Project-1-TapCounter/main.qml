import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: rootWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Tap Counter")

    property int counter: 0

    Button {
        id: resetButton
        text: "Reset"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 10
        anchors.topMargin: 10
        onClicked: {
            rootWindow.counter = 0
        }
    }

    Label {
        id: counterLabel
        text: "Counter"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
    }

    Text {
        id: counterText
        text: Number(rootWindow.counter)
        font.family: "Helvetica"
        font.pointSize: 60
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Button {
        id: tapButton
        text: "Tap"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: counterText.bottom
        anchors.topMargin: 30
        onClicked: {
            rootWindow.counter++
        }
    }
}
