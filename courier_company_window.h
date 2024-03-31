#pragma once
#include <QWidget>
#include "session.h"
#include "observer.h"


namespace Ui { class courier_company_window; }

class courier_company_window : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit courier_company_window(Session &sess, QWidget *parent = nullptr);

    void update() override;

    ~courier_company_window() override;

private:
    Ui::courier_company_window *ui;
    Session &sess;

    void populatePackagesList();
};
