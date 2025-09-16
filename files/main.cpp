#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Minimal Search");
    window.resize(800, 600);

    QLineEdit *searchBox = new QLineEdit();
    searchBox->setPlaceholderText("Search...");
    searchBox->setStyleSheet(
        "QLineEdit { "
        "background-color: #3b3b3b; "
        "color: white; "
        "border-radius: 10px; "
        "padding: 10px; "
        "font-size: 18px; "
        "}"
    );

    QPushButton *searchButton = new QPushButton("Go");
    searchButton->setStyleSheet(
        "QPushButton { "
        "background-color: #555; "
        "color: white; "
        "padding: 10px 15px; "
        "border-radius: 8px; "
        "}"
    );

    QWebEngineView *browser = new QWebEngineView();
    browser->setUrl(QUrl("about:blank"));

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchBox);
    searchLayout->addWidget(searchButton);
    layout->addLayout(searchLayout);
    layout->addWidget(browser);

    QObject::connect(searchButton, &QPushButton::clicked, [&](){
        QString query = searchBox->text().trimmed();
        if(!query.isEmpty()) {
            QString url = "https://www.google.com/search?q=" + QUrl::toPercentEncoding(query);
            browser->setUrl(QUrl(url));
        }
    });

    QObject::connect(searchBox, &QLineEdit::returnPressed, [&](){
        QString query = searchBox->text().trimmed();
        if(!query.isEmpty()) {
            QString url = "https://www.google.com/search?q=" + QUrl::toPercentEncoding(query);
            browser->setUrl(QUrl(url));
        }
    });

    window.show();
    return app.exec();
}
