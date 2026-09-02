#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(NULL, NULL);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Bus Reservation System");
    // ... (rest of your code)

    // Connect the destroy signal to g_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(g_main_quit), NULL);

    // ... (rest of your code)

    // Start the GTK main loop
    gtk_main();

    return 0;
}
