#ifndef MENU_H
#define MENU_H


class menu
{
    public:
        menu();
        virtual ~menu();
        int MenuNivel();
        void Load();
        void Logo();
        void LogoMin();
        int MenuInic();
        int MenuValida(int j);
        void Instructions();

    protected:

    private:
};

#endif // MENU_H
