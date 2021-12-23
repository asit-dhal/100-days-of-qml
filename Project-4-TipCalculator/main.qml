import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tip Calculator")

    property int tipAmount: 0
    property int tipPercentage : 15

    ColumnLayout {
        spacing: 2
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        Text {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            id: headerText
            text: "Tip Calculator"
            height: 20
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
            font.bold: true
        }

        Rectangle {
            id: headerSeparator
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            height: 1
            color: "grey"
        }

        GridLayout {
            id: layout
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignRight | Qt.AlignTop
            rows: 3
            columns: 2

            TextField {
                id: tipAmountTextField
                placeholderText: "$0.00"
                font.pixelSize: 60
                GridLayout.columnSpan: 2
                Layout.alignment: Qt.AlignRight | Qt.AlignTop
            }

            Text { text: "Tip (" + Number(tipPercentage) + "%)" }
            Text { text: "$" + Number(tipAmount*tipPercentage/100) }
            Text { text: "Total:" }
            Text { text: "$" + Number(tipAmount + tipAmount*tipPercentage/100) }
        }

        Slider {
            from: 1
            value: 15
            to: 200
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            onValueChanged: {
                tipPercentage = value
            }
        }

    }
}
