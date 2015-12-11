#include "comboBoxItemDelegate.h"
#include <QComboBox>

// CONSTRUCTOR/DESTRUCTOR
ComboBoxItemDelegate::ComboBoxItemDelegate(QObject* parent) : QStyledItemDelegate(parent) {

}

ComboBoxItemDelegate::~ComboBoxItemDelegate() {
}


// PUBLIC METHODS
QWidget* ComboBoxItemDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {

    // ComboBox ony in column 2
    if (index.column() != this->rowIndex) {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }

    // Create the combobox and populate it
    QComboBox* cb = new QComboBox(parent);

    for(int i = 0; i < this->options.size(); i++) {

        cb->addItem(this->options[i]);

    }

    return cb;
}

void ComboBoxItemDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {

    if (QComboBox* cb = qobject_cast<QComboBox*>(editor)) {

        // get the index of the text in the combobox that matches the current value of the item
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);

        // if it is valid, adjust the combobox
        if (cbIndex >= 0) {

           cb->setCurrentIndex(cbIndex);

        }

    } else {

        QStyledItemDelegate::setEditorData(editor, index);

    }

    return;
}


void ComboBoxItemDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {

    if (QComboBox* cb = qobject_cast<QComboBox*>(editor)) {
        // save the current text of the combo box as the current value of the item
        model->setData(index, cb->currentText(), Qt::EditRole);
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

    return;
}

void ComboBoxItemDelegate::addOption(QString option) {

    this->options.push_back(option);

    return;
}

void ComboBoxItemDelegate::setColumnIndex(int index) {

    this->rowIndex = index;

    return;
}
