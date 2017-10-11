// vim: noet ts=4 sw=4
#include <gtk/gtk.h>

#define WIDTH 550
#define HEIGHT 460

static void activate(GtkApplication* app, gpointer user_data) {
	GtkWidget *window = NULL;
	window = gtk_application_window_new(app);

	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
	GtkApplication *app = NULL;
	int status = 0;

	app = gtk_application_new("org.quinlan.star_button", G_APPLICATION_FLAGS_NONE);
	if (!app) {
		printf("Could not start new app.\n");
		return -1;
	}
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref (app);

	return status;
}
