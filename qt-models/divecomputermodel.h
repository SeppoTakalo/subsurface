// SPDX-License-Identifier: GPL-2.0
#ifndef DIVECOMPUTERMODEL_H
#define DIVECOMPUTERMODEL_H

#include "qt-models/cleanertablemodel.h"
#include "core/divecomputer.h"

class DiveComputerModel : public CleanerTableModel {
	Q_OBJECT
public:
	enum {
		REMOVE,
		MODEL,
		ID,
		NICKNAME
	};
	DiveComputerModel(QObject *parent = 0);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	void keepWorkingList();

public
slots:
	void remove(const QModelIndex &index);

private:
	int numRows;
	QVector<DiveComputerNode> dcs;
};

#endif
