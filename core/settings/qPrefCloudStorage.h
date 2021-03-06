// SPDX-License-Identifier: GPL-2.0
#ifndef QPREFCLOUDSTORAGE_H
#define QPREFCLOUDSTORAGE_H
#include "core/pref.h"

#include <QObject>

class qPrefCloudStorage : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString cloud_base_url READ cloud_base_url WRITE set_cloud_base_url NOTIFY cloud_base_url_changed);
	Q_PROPERTY(QString cloud_git_url READ cloud_git_url);
	Q_PROPERTY(QString cloud_storage_email READ cloud_storage_email WRITE set_cloud_storage_email NOTIFY cloud_storage_email_changed);
	Q_PROPERTY(QString cloud_storage_email_encoded READ cloud_storage_email_encoded WRITE set_cloud_storage_email_encoded NOTIFY cloud_storage_email_encoded_changed);
	Q_PROPERTY(QString cloud_storage_newpassword READ cloud_storage_newpassword WRITE set_cloud_storage_newpassword NOTIFY cloud_storage_newpassword_changed);
	Q_PROPERTY(QString cloud_storage_password READ cloud_storage_password WRITE set_cloud_storage_password NOTIFY cloud_storage_password_changed);
	Q_PROPERTY(QString cloud_storage_pin READ cloud_storage_pin WRITE set_cloud_storage_pin NOTIFY cloud_storage_pin_changed);
	Q_PROPERTY(int cloud_verification_status READ cloud_verification_status WRITE set_cloud_verification_status NOTIFY cloud_verification_status_changed);
	Q_PROPERTY(int cloud_timeout READ cloud_timeout WRITE set_cloud_timeout NOTIFY cloud_timeout_changed);
	Q_PROPERTY(bool git_local_only READ git_local_only WRITE set_git_local_only NOTIFY git_local_only_changed);
	Q_PROPERTY(bool save_password_local READ save_password_local WRITE set_save_password_local NOTIFY save_password_local_changed);
	Q_PROPERTY(bool save_userid_local READ save_userid_local WRITE set_save_userid_local NOTIFY save_userid_local_changed);
	Q_PROPERTY(QString userid READ userid WRITE set_userid NOTIFY userid_changed);

public:
	qPrefCloudStorage(QObject *parent = NULL);
	static qPrefCloudStorage *instance();

	// Load/Sync local settings (disk) and struct preference
	static void loadSync(bool doSync);
	static void load() { loadSync(false); }
	static void sync() { loadSync(true); }

public:
	static QString cloud_base_url() { return prefs.cloud_base_url; }
	static QString cloud_git_url() { return prefs.cloud_git_url; }
	static QString cloud_storage_email() { return prefs.cloud_storage_email; }
	static QString cloud_storage_email_encoded() { return prefs.cloud_storage_email_encoded; }
	static QString cloud_storage_newpassword() { return prefs.cloud_storage_newpassword; }
	static QString cloud_storage_password() { return prefs.cloud_storage_password; }
	static QString cloud_storage_pin() { return prefs.cloud_storage_pin; }
	static int cloud_timeout() { return prefs.cloud_timeout; }
	static int cloud_verification_status() { return prefs.cloud_verification_status; }
	static bool git_local_only() { return prefs.git_local_only; }
	static bool save_password_local() { return prefs.save_password_local; }
	static bool save_userid_local() { return prefs.save_userid_local; }
	static QString userid() { return prefs.userid; }

public slots:
	static void set_cloud_base_url(const QString &value);
	static void set_cloud_storage_email(const QString &value);
	static void set_cloud_storage_email_encoded(const QString &value);
	static void set_cloud_storage_newpassword(const QString &value);
	static void set_cloud_storage_password(const QString &value);
	static void set_cloud_storage_pin(const QString &value);
	static void set_cloud_timeout(int value);
	static void set_cloud_verification_status(int value);
	static void set_git_local_only(bool value);
	static void set_save_password_local(bool value);
	static void set_save_userid_local(bool value);
	static void set_userid(const QString &value);

signals:
	void cloud_base_url_changed(const QString &value);
	void cloud_storage_email_changed(const QString &value);
	void cloud_storage_email_encoded_changed(const QString &value);
	void cloud_storage_newpassword_changed(const QString &value);
	void cloud_storage_password_changed(const QString &value);
	void cloud_storage_pin_changed(const QString &value);
	void cloud_timeout_changed(int value);
	void cloud_verification_status_changed(int value);
	void git_local_only_changed(bool value);
	void save_password_local_changed(bool value);
	void save_userid_local_changed(bool value);
	void userid_changed(const QString &value);

private:
	// functions to load/sync variable with disk
	static void disk_cloud_base_url(bool doSync);
	static void disk_cloud_storage_email(bool doSync);
	static void disk_cloud_storage_email_encoded(bool doSync);
	static void disk_cloud_storage_newpassword(bool doSync);
	static void disk_cloud_storage_password(bool doSync);
	static void disk_cloud_storage_pin(bool doSync);
	static void disk_cloud_timeout(bool doSync);
	static void disk_cloud_verification_status(bool doSync);
	static void disk_git_local_only(bool doSync);
	static void disk_save_password_local(bool doSync);
	static void disk_save_userid_local(bool doSync);
	static void disk_userid(bool doSync);
};

#endif
