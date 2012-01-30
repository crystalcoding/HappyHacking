using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace game_of_life
{
    /// <summary>
    /// Interaction logic for DormCell.xaml
    /// </summary>
    public partial class DormCell : Button
    {
        private int dormRow;
        private int dormCol;
        private bool alive;
        private bool futureAlive;
        private DormManager dormManager;
        
        public DormCell(int row, int col, DormManager dm)
        {
            DormRow = row;
            DormCol = col;
            alive = false;
            futureAlive = false;
            dormManager = dm;
            dm.SetRoomStatus(alive, row, col);
            InitializeComponent();
            this.UpdateLayout();
        }

        public int DormRow 
        {   
            get {return dormRow;}
            set { dormRow = value; }        
        }

        public int DormCol
        {
            get { return dormCol; }
            set { dormCol = value; }
        }

        public bool Alive
        {
            get { return alive; }
            set { alive = value; }
        }

        public bool FutureAlive
        {
            get { return futureAlive; }
            set { futureAlive = value; }
        }

        public void drawPrettyColor()
        {
            if (alive) this.Background= new System.Windows.Media.SolidColorBrush(Color.FromRgb(0,255,0));
            else this.Background = new System.Windows.Media.SolidColorBrush(Color.FromRgb(255,255,255));
        }
        
        void DormCellClick(object sender, RoutedEventArgs e)
        {
            if (alive) alive = false;
            else alive = true;
            dormManager.SetRoomStatus(alive, dormRow, dormCol);
            drawPrettyColor();
            //this.Content = alive.ToString();
            UpdateLayout();
        }
    }
}
