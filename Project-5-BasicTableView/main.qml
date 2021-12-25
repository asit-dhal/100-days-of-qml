import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls.Material 2.15

Window {
    width: 320
    height: 480
    visible: true
    title: qsTr("QML list view")
    Material.theme: Material.Dark

    ListView {
        id: movieView
        anchors.fill: parent
        anchors.margins: 20
        clip: true
        model: movieModel
        delegate: movieDelegate
        highlight: highlight
        focus: true

        ScrollBar.vertical: ScrollBar {
            id: listViewScrollBar
            active: true
        }
    }

    Component {
        id: highlight
        Rectangle {
            y: movieView.currentItem.y
            color: "green"
            Behavior on y {
                SpringAnimation {
                    spring: 3
                    damping: 0.2
                }
            }
        }
    }

    Component {
        id: movieDelegate
        ColumnLayout {
            width: movieView.width - listViewScrollBar.width
            id: filmColLayout
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredWidth: movieView.width - listViewScrollBar.width
                Text {
                    id: filmNameText
                    text: film
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignLeft
                    MouseArea {
                        anchors.fill: filmNameText
                        onClicked: movieView.currentIndex = index
                    }
                }
            }

            Text {
                id: genreText
                text: genre
                font.italic: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignLeft
                MouseArea {
                    anchors.fill: genreText
                    onClicked: movieView.currentIndex = index
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 1
                Layout.preferredWidth: 70
                color: "black"
            }
        }
    }

}
