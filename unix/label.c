// 11 june 2015
#include "uipriv_unix.h"

struct uiLabel {
	uiUnixControl c;
	GtkWidget *widget;
	GtkMisc *misc;
	GtkLabel *label;
};

uiUnixControlAllDefaults(uiLabel)

char *uiLabelText(uiLabel *l)
{
	return uiUnixStrdupText(gtk_label_get_text(l->label));
}

void uiLabelSetText(uiLabel *l, const char *text)
{
	gtk_label_set_text(l->label, text);
}

void uiLabelSetAlignment(uiLabel *l, uiDrawTextAlign align)
{
    float alignment = 0;
    if (align == uiDrawTextAlignCenter) {
        alignment = 0.5;
    } else if (align == uiDrawTextAlignRight) {
        alignment = 1.0;
    }

    gtk_misc_set_alignment(l->misc, alignment, 0);
}

uiLabel *uiNewLabel(const char *text)
{
	uiLabel *l;

	uiUnixNewControl(uiLabel, l);

	l->widget = gtk_label_new(text);
	l->misc = GTK_MISC(l->widget);
	l->label = GTK_LABEL(l->widget);

	gtk_misc_set_alignment(l->misc, 0, 0);

	return l;
}
