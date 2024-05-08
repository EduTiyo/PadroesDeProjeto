#include <iostream>
#include <string>

class Editor {
private:
    std::string text;
    int curX, curY, selectionWidth;

public:
    void setText(const std::string& text) {
        this->text = text;
    }

    void setCursor(int x, int y) {
        curX = x;
        curY = y;
    }

    void setSelectionWidth(int width) {
        selectionWidth = width;
    }

    class Snapshot; 

    Snapshot createSnapshot();
};

class Editor::Snapshot {
private:
    Editor* editor;
    std::string text;
    int curX, curY, selectionWidth;

public:
    Snapshot(Editor* editor, const std::string& text, int curX, int curY, int selectionWidth)
        : editor(editor), text(text), curX(curX), curY(curY), selectionWidth(selectionWidth) {}

    void restore() {
        editor->setText(text);
        editor->setCursor(curX, curY);
        editor->setSelectionWidth(selectionWidth);
    }
};

Editor::Snapshot Editor::createSnapshot() {
    return Snapshot(this, text, curX, curY, selectionWidth);
}

class Command {
private:
    Editor::Snapshot backup;

public:
    Command(Editor* editor) : backup(editor->createSnapshot()) {}

    void makeBackup(Editor* editor) {
        backup = editor->createSnapshot();
    }

    void undo() {
        backup.restore();
    }
};

int main() {
    Editor editor;
    editor.setText("Hello, World!");
    editor.setCursor(10, 5);
    editor.setSelectionWidth(5);

    Command command(&editor);
    editor.setText("Goodbye, World!");
    command.undo();
    return 0;
}
