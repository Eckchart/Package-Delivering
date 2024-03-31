#pragma once
#include <QWidget>
#include "repository.h"
#include "observer.h"
#include "session.h"


namespace Ui { class courier_window; }

class courier_window : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit courier_window(Session&, const Courier, QWidget *parent = nullptr);

    void update() override;

    ~courier_window() override;

private:
    Ui::courier_window *ui;
    Session &sess;
    Courier cur_courier;

    void populatePackagesList();

    void populateComboBox();

    static int get_sq_dist(int, int, int, int);
};
