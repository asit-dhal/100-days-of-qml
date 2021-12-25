#pragma once

#include "Movie.h"
#include <QAbstractListModel>

class MovieModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum AnimalRoles
    {
        FilmRole = Qt::UserRole + 1,
        GenreRole,
        LeadStudioRole,
        AudienceScoreRole,
        ProfitabilityRole,
        RottenTomatoesRole,
        WorldwideGrossRole,
        YearRole,
    };
    Q_ENUM(AnimalRoles)

    explicit MovieModel(QObject *parent = nullptr);
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

private:
    void populateData();

private:
    QList<Movie> m_movies;
};

