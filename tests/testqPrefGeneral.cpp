// SPDX-License-Identifier: GPL-2.0
#include "testqPrefGeneral.h"

#include "core/pref.h"
#include "core/qthelper.h"
#include "core/settings/qPref.h"

#include <QTest>

void TestQPrefGeneral::initTestCase()
{
	QCoreApplication::setOrganizationName("Subsurface");
	QCoreApplication::setOrganizationDomain("subsurface.hohndel.org");
	QCoreApplication::setApplicationName("SubsurfaceTestQPrefGeneral");
}

void TestQPrefGeneral::test_struct_get()
{
	// Test struct pref -> get func.

	auto tst = qPrefGeneral::instance();

	prefs.auto_recalculate_thumbnails = true;
	prefs.default_cylinder = copy_qstring("new base11");
	prefs.default_filename = copy_qstring("new base12");
	prefs.default_file_behavior = UNDEFINED_DEFAULT_FILE;
	prefs.defaultsetpoint = 14;
	prefs.extract_video_thumbnails = true;
	prefs.extract_video_thumbnails_position = 15;
	prefs.ffmpeg_executable = copy_qstring("new base16");
	prefs.o2consumption = 17;
	prefs.pscr_ratio = 18;
	prefs.use_default_file = true;

	QCOMPARE(tst->auto_recalculate_thumbnails(), prefs.auto_recalculate_thumbnails);
	QCOMPARE(tst->default_cylinder(), QString(prefs.default_cylinder));
	QCOMPARE(tst->default_filename(), QString(prefs.default_filename));
	QCOMPARE(tst->default_file_behavior(), prefs.default_file_behavior);
	QCOMPARE(tst->defaultsetpoint(), prefs.defaultsetpoint);
	QCOMPARE(tst->extract_video_thumbnails(), prefs.extract_video_thumbnails);
	QCOMPARE(tst->extract_video_thumbnails_position(), prefs.extract_video_thumbnails_position);
	QCOMPARE(tst->ffmpeg_executable(), QString(prefs.ffmpeg_executable));
	QCOMPARE(tst->o2consumption(), prefs.o2consumption);
	QCOMPARE(tst->pscr_ratio(), prefs.pscr_ratio);
	QCOMPARE(tst->use_default_file(), prefs.use_default_file);
}

void TestQPrefGeneral::test_set_struct()
{
	// Test set func -> struct pref

	auto tst = qPrefGeneral::instance();

	tst->set_auto_recalculate_thumbnails(false);
	tst->set_default_cylinder("new base21");
	tst->set_default_filename("new base22");
	tst->set_default_file_behavior(LOCAL_DEFAULT_FILE);
	tst->set_defaultsetpoint(24);
	tst->set_extract_video_thumbnails(false);
	tst->set_extract_video_thumbnails_position(25);
	tst->set_ffmpeg_executable("new base26");
	tst->set_o2consumption(27);
	tst->set_pscr_ratio(28);
	tst->set_use_default_file(false);

	QCOMPARE(prefs.auto_recalculate_thumbnails, false);
	QCOMPARE(QString(prefs.default_cylinder), QString("new base21"));
	QCOMPARE(QString(prefs.default_filename), QString("new base22"));
	QCOMPARE(prefs.default_file_behavior, LOCAL_DEFAULT_FILE);
	QCOMPARE(prefs.defaultsetpoint, 24);
	QCOMPARE(prefs.extract_video_thumbnails, false);
	QCOMPARE(prefs.extract_video_thumbnails_position, 25);
	QCOMPARE(QString(prefs.ffmpeg_executable), QString("new base26"));
	QCOMPARE(prefs.o2consumption, 27);
	QCOMPARE(prefs.pscr_ratio, 28);
	QCOMPARE(prefs.use_default_file, false);
}

void TestQPrefGeneral::test_set_load_struct()
{
	// test set func -> load -> struct pref

	auto tst = qPrefGeneral::instance();

	tst->set_auto_recalculate_thumbnails(true);
	tst->set_default_cylinder("new base31");
	tst->set_default_filename("new base32");
	tst->set_default_file_behavior(NO_DEFAULT_FILE);
	tst->set_defaultsetpoint(34);
	tst->set_extract_video_thumbnails(true);
	tst->set_extract_video_thumbnails_position(35);
	tst->set_ffmpeg_executable("new base36");
	tst->set_o2consumption(37);
	tst->set_pscr_ratio(38);
	tst->set_use_default_file(true);

	prefs.auto_recalculate_thumbnails = false;
	prefs.default_cylinder = copy_qstring("error");
	prefs.default_filename = copy_qstring("error");
	prefs.default_file_behavior = UNDEFINED_DEFAULT_FILE;
	prefs.defaultsetpoint = 14;
	prefs.extract_video_thumbnails = false;
	prefs.extract_video_thumbnails_position = 15;
	prefs.ffmpeg_executable = copy_qstring("error");
	prefs.o2consumption = 17;
	prefs.pscr_ratio = 18;
	prefs.use_default_file = false;

	tst->load();
	QCOMPARE(prefs.auto_recalculate_thumbnails, true);
	QCOMPARE(QString(prefs.default_cylinder), QString("new base31"));
	QCOMPARE(QString(prefs.default_filename), QString("new base32"));
	QCOMPARE(prefs.default_file_behavior, NO_DEFAULT_FILE);
	QCOMPARE(prefs.defaultsetpoint, 34);
	QCOMPARE(prefs.extract_video_thumbnails, true);
	QCOMPARE(prefs.extract_video_thumbnails_position, 35);
	QCOMPARE(QString(prefs.ffmpeg_executable), QString("new base36"));
	QCOMPARE(prefs.o2consumption, 37);
	QCOMPARE(prefs.pscr_ratio, 38);
	QCOMPARE(prefs.use_default_file, true);
}

void TestQPrefGeneral::test_struct_disk()
{
	// test struct prefs -> disk

	auto tst = qPrefGeneral::instance();

	prefs.auto_recalculate_thumbnails = true;
	prefs.default_cylinder = copy_qstring("base41");
	prefs.default_filename = copy_qstring("base42");
	prefs.default_file_behavior = CLOUD_DEFAULT_FILE;
	prefs.defaultsetpoint = 44;
	prefs.extract_video_thumbnails = true;
	prefs.extract_video_thumbnails_position = 45;
	prefs.ffmpeg_executable = copy_qstring("base46");
	prefs.o2consumption = 47;
	prefs.pscr_ratio = 48;
	prefs.use_default_file = true;

	tst->sync();
	prefs.auto_recalculate_thumbnails = false;
	prefs.default_cylinder = copy_qstring("error");
	prefs.default_filename = copy_qstring("error");
	prefs.default_file_behavior = UNDEFINED_DEFAULT_FILE;
	prefs.defaultsetpoint = 14;
	prefs.extract_video_thumbnails = false;
	prefs.extract_video_thumbnails_position = 15;
	prefs.ffmpeg_executable = copy_qstring("error");
	prefs.o2consumption = 17;
	prefs.pscr_ratio = 18;
	prefs.use_default_file = false;

	tst->load();
	QCOMPARE(prefs.auto_recalculate_thumbnails, true);
	QCOMPARE(QString(prefs.default_cylinder), QString("base41"));
	QCOMPARE(QString(prefs.default_filename), QString("base42"));
	QCOMPARE(prefs.default_file_behavior, CLOUD_DEFAULT_FILE);
	QCOMPARE(prefs.defaultsetpoint, 44);
	QCOMPARE(prefs.extract_video_thumbnails, true);
	QCOMPARE(prefs.extract_video_thumbnails_position, 45);
	QCOMPARE(QString(prefs.ffmpeg_executable), QString("base46"));
	QCOMPARE(prefs.o2consumption, 47);
	QCOMPARE(prefs.pscr_ratio, 48);
	QCOMPARE(prefs.use_default_file, true);
}

void TestQPrefGeneral::test_multiple()
{
	// test multiple instances have the same information

	prefs.o2consumption = 17;
	auto tst_direct = new qPrefGeneral;

	prefs.pscr_ratio = 18;
	auto tst = qPrefGeneral::instance();

	QCOMPARE(tst->o2consumption(), tst_direct->o2consumption());
	QCOMPARE(tst->pscr_ratio(), tst_direct->pscr_ratio());
	QCOMPARE(tst_direct->o2consumption(), 17);
	QCOMPARE(tst_direct->pscr_ratio(), 18);
}

#define TEST(METHOD, VALUE)      \
	QCOMPARE(METHOD, VALUE); \
	general->sync();           \
	general->load();           \
	QCOMPARE(METHOD, VALUE);

void TestQPrefGeneral::test_oldPreferences()
{
	auto general = qPrefGeneral::instance();

	general->set_default_filename("filename");
	general->set_default_cylinder("cylinder_2");
	general->set_default_file_behavior(LOCAL_DEFAULT_FILE);
	general->set_defaultsetpoint(0);
	general->set_o2consumption(0);
	general->set_pscr_ratio(0);
	general->set_use_default_file(true);

	TEST(general->default_filename(), QStringLiteral("filename"));
	TEST(general->default_cylinder(), QStringLiteral("cylinder_2"));
	TEST(general->default_file_behavior(), LOCAL_DEFAULT_FILE); // since we have a default file, here it returns
	TEST(general->defaultsetpoint(), 0);
	TEST(general->o2consumption(), 0);
	TEST(general->pscr_ratio(), 0);
	TEST(general->use_default_file(), true);

	general->set_default_filename("no_file_name");
	general->set_default_cylinder("cylinder_1");
	//TODOl: Change this to a enum.
	general->set_default_file_behavior(CLOUD_DEFAULT_FILE);

	general->set_defaultsetpoint(1);
	general->set_o2consumption(1);
	general->set_pscr_ratio(1);
	general->set_use_default_file(false);

	TEST(general->default_filename(), QStringLiteral("no_file_name"));
	TEST(general->default_cylinder(), QStringLiteral("cylinder_1"));
	TEST(general->default_file_behavior(), CLOUD_DEFAULT_FILE);
	TEST(general->defaultsetpoint(), 1);
	TEST(general->o2consumption(), 1);
	TEST(general->pscr_ratio(), 1);
	TEST(general->use_default_file(), false);
}

QTEST_MAIN(TestQPrefGeneral)
