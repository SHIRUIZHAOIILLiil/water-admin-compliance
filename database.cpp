#include "csv.hpp"
#include "database.hpp"
#include <QtSql>

using namespace std;

void WaterDataset::loadData(const string &filename)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("watertest4.db");

    if (!db.open())
    {
        qDebug() << "Cannot open database:" << db.lastError();
        throw runtime_error("Cannot open database");
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS waterdata (id INTEGER PRIMARY KEY, id_web TEXT unique, "
               " sample_samplingPoint TEXT,"
               "sample_samplingPoint_notation TEXT,"
               "sample_samplingPoint_label TEXT,"
               "sample_sampleDateTime TEXT,"
               "determinand_label TEXT,"
               "determinand_definition TEXT,"
               "determinand_notation INTEGER,"
               "resultQualifier_notation TEXT,"
               "result REAL,"
               "codedResultInterpretation_interpretation TEXT,"
               "determinand_unit_label TEXT,"
               "sample_sampledMaterialType_label TEXT,"
               "sample_isComplianceSample TEXT,"
               "sample_purpose_label TEXT,"
               "sample_samplingPoint_easting INTEGER,"
               "sample_samplingPoint_northing INTEGER)");
    csv::CSVReader reader(filename);

    // QString insert_query = "INSERT INTO waterdata (id_web, sample_samplingPoint, sample_samplingPoint_notation, sample_samplingPoint_label,"
    //                                           "sample_sampleDateTime, determinand_label, determinand_definition,"
    //                                           "determinand_notation, resultQualifier_notation, result,"
    //                                           "codedResultInterpretation_interpretation, determinand_unit_label,"
    //                                           "sample_sampledMaterialType_label, sample_isComplianceSample,"
    //                                           "sample_purpose_label, sample_samplingPoint_easting, sample_samplingPoint_northing"
    //                                           ") VALUES (:id_web, :sample_samplingPoint,"
    //                                                             ":sample_samplingPoint_notation,"
    //                                                             ":sample_samplingPoint_label,"
    //                                                             ":sample_sampleDateTime,"
    //                                                             ":determinand_label,"
    //                                                             ":determinand_definition,"
    //                                                             ":determinand_notation,"
    //                                                             ":resultQualifier_notation,"
    //                                                             ":result,"
    //                                                             ":codedResultInterpretation_interpretation,"
    //                                                             ":determinand_unit_label,"
    //                                                             ":sample_sampledMaterialType_label,"
    //                                                             ":sample_isComplianceSample,"
    //                                                             ":sample_purpose_label,"
    //                                                             ":sample_samplingPoint_easting,"
    //                                                             ":sample_samplingPoint_northing)";

    for (const auto &row : reader)
    {

        //     query.prepare("SELECT COUNT(*) FROM waterdata WHERE id_web = :id_web");

        //     query.bindValue(":id_web", QString::fromStdString(row["@id"].get<>()));
        //     query.exec();
        //     query.next();
        //     if (query.value(0).toInt() > 0) {
        //     db.rollback();
        //     continue;
        // }

        query.prepare("INSERT INTO waterdata (id_web, sample_samplingPoint, sample_samplingPoint_notation, sample_samplingPoint_label,"
                      "sample_sampleDateTime, determinand_label, determinand_definition,"
                      "determinand_notation, resultQualifier_notation, result,"
                      "codedResultInterpretation_interpretation, determinand_unit_label,"
                      "sample_sampledMaterialType_label, sample_isComplianceSample,"
                      "sample_purpose_label, sample_samplingPoint_easting, sample_samplingPoint_northing"
                      ") VALUES (:id_web, :sample_samplingPoint,"
                      ":sample_samplingPoint_notation,"
                      ":sample_samplingPoint_label,"
                      ":sample_sampleDateTime,"
                      ":determinand_label,"
                      ":determinand_definition,"
                      ":determinand_notation,"
                      ":resultQualifier_notation,"
                      ":result,"
                      ":codedResultInterpretation_interpretation,"
                      ":determinand_unit_label,"
                      ":sample_sampledMaterialType_label,"
                      ":sample_isComplianceSample,"
                      ":sample_purpose_label,"
                      ":sample_samplingPoint_easting,"
                      ":sample_samplingPoint_northing)");

        query.bindValue(":id_web", QString::fromStdString((row["@id"].get<>())));
        query.bindValue(":sample_samplingPoint", QString::fromStdString(row["sample.samplingPoint"].get<>()));
        query.bindValue(":sample_samplingPoint_notation", QString::fromStdString(row["sample.samplingPoint.notation"].get<>()));
        query.bindValue(":sample_samplingPoint_label", QString::fromStdString(row["sample.samplingPoint.label"].get<>()));
        query.bindValue(":sample_sampleDateTime", QString::fromStdString(row["sample.sampleDateTime"].get<>()));
        query.bindValue(":determinand_label", QString::fromStdString(row["determinand.label"].get<>()));
        query.bindValue(":determinand_definition", QString::fromStdString(row["determinand.definition"].get<>()));
        query.bindValue(":determinand_notation", QVariant::fromValue(row["determinand.notation"].get<int>()));
        query.bindValue(":resultQualifier_notation", QString::fromStdString(row["resultQualifier.notation"].get<>()));
        query.bindValue(":result", QVariant::fromValue(row["result"].get<double>()));
        query.bindValue(":codedResultInterpretation_interpretation",
                        QString::fromStdString(row["codedResultInterpretation.interpretation"].get<>()));
        query.bindValue(":determinand_unit_label", QString::fromStdString(row["determinand.unit.label"].get<>()));
        query.bindValue(":sample_sampledMaterialType_label", QString::fromStdString(row["sample.sampledMaterialType.label"].get<>()));
        query.bindValue(":sample_isComplianceSample", QString::fromStdString(row["sample.isComplianceSample"].get<>()));
        query.bindValue(":sample_purpose_label", QString::fromStdString(row["sample.purpose.label"].get<>()));
        query.bindValue(":sample_samplingPoint_easting", QVariant::fromValue(row["sample.samplingPoint.easting"].get<int>()));
        query.bindValue(":sample_samplingPoint_northing", QVariant::fromValue(row["sample.samplingPoint.northing"].get<int>()));
        if (!query.exec())
        {
            if (query.lastError().nativeErrorCode() == "2067")
            {
                //qDebug() << "Record already exists, skipping insert.";
                db.rollback();
                continue;
            }
            else
            {
                qDebug() << "Insert error:" << query.lastError();
                db.rollback();
                continue;
            }
        }
    }

}
