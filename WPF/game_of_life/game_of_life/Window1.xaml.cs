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

//Game of Life in WPF by Glenn C. 6/16/2009
namespace game_of_life
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        private DormManager dormManager;
        private Grid dormGrid;
        public Window1()
        {
            InitializeComponent();
            initialize_grid(15, 15);
        }

        public void initialize_grid(int n, int m)
        {
            dormManager = new DormManager(n, m);

            dormGrid = new Grid();
            dormGrid.Width = 200;
            dormGrid.Height = 200;
            dormGrid.ShowGridLines = true;

            for (int i = 0; i < n; ++i)
            {
                dormGrid.ColumnDefinitions.Add(new ColumnDefinition());
            }
            for (int i = 0; i < m; ++i)
            {
                dormGrid.RowDefinitions.Add(new RowDefinition());
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    DormCell dc = new DormCell(i, j, dormManager);
                    Grid.SetRow(dc,i); // why not dormGrid.SetRow? but Grid.setrow?
                    Grid.SetColumn(dc,j);
                    dormGrid.Children.Add(dc);
                    dormManager.SetRoomStatus(dc.Alive, i, j);
                }
            }

            StackPanel sp = new StackPanel();
            Button runOnceButton = new Button();
            runOnceButton.Content = "Run Once";
            runOnceButton.Click += new RoutedEventHandler(UpdateGrid);
            runOnceButton.Height = 50;
            runOnceButton.Width = 200;

            sp.Children.Add(dormGrid);
            sp.Children.Add(runOnceButton);
            this.Content = sp;
            this.Width = 220;
            this.Height = 290;

            this.UpdateLayout();
        }

        void setFutureStatusForEachCell()
        {
            foreach (object o in dormGrid.Children)
            {
                DormCell dc = (DormCell)o;
                dc.FutureAlive = dormManager.checkFutureStatus(dc.Alive, dc.DormRow, dc.DormCol);
            }
        }

        void UpdateGrid(Object sender, RoutedEventArgs e)
        {
            setFutureStatusForEachCell();

            foreach (object o in dormGrid.Children)
            {
                DormCell dc = (DormCell)o;
                dc.Alive = dc.FutureAlive;
                //bug! need to update DormManager's status 
                dormManager.SetRoomStatus(dc.Alive, Grid.GetRow(dc), Grid.GetColumn(dc));

                //dc.Content = dc.Alive.ToString();
                dc.drawPrettyColor();
                dc.FutureAlive = false;
            }
        }
    }
}
