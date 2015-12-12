
#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QString>
#include <QStyledItemDelegate>
#include <QVector>

class ComboBoxItemDelegate : public QStyledItemDelegate {
    Q_OBJECT

    public:
        ComboBoxItemDelegate(QObject* parent=0);
        ~ComboBoxItemDelegate();

        virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
        virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;
        virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

        void addOption(QString option);
        void setColumnIndex(int index);

    private:

        QVector<QString> options;
        int rowIndex;
};

#endif // ITEMDELEGATE_H
