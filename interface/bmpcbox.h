/////////////////////////////////////////////////////////////////////////////
// Name:        bmpcbox.h
// Purpose:     documentation for wxBitmapComboBox class
// Author:      wxWidgets team
// RCS-ID:      $Id$
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

/**
    @class wxBitmapComboBox
    @wxheader{bmpcbox.h}

    A combobox that displays bitmap in front of the list items.
    It currently only allows using bitmaps of one size, and resizes itself
    so that a bitmap can be shown next to the text field.

    @beginStyleTable
    @style{wxCB_READONLY}:
           Creates a combobox without a text editor. On some platforms the
           control may appear very different when this style is used.
    @style{wxCB_SORT}:
           Sorts the entries in the list alphabetically.
    @style{wxTE_PROCESS_ENTER}:
           The control will generate the event wxEVT_COMMAND_TEXT_ENTER
           (otherwise pressing Enter key is either processed internally by the
           control or used for navigation between dialog controls). Windows
           only.
    @endStyleTable

    @beginEventTable
    @event{EVT_COMBOBOX(id, func)}:
           Process a wxEVT_COMMAND_COMBOBOX_SELECTED event, when an item on
           the list is selected.
    @event{EVT_TEXT(id, func)}:
           Process a wxEVT_COMMAND_TEXT_UPDATED event, when the combobox text
           changes.
    @event{EVT_TEXT_ENTER(id, func)}:
           Process a wxEVT_COMMAND_TEXT_ENTER event, when RETURN is pressed in
           the combobox.
    @endEventTable

    @library{wxadv}
    @category{ctrl}
    @appearance{bitmapcombobox.png}

    @seealso
    wxComboBox, wxChoice, wxOwnerDrawnComboBox, wxCommandEvent
*/
class wxBitmapComboBox : public wxComboBox
{
public:
    //@{
    /**
        Constructor, creating and showing a combobox.
        
        @param parent
            Parent window. Must not be @NULL.
        @param id
            Window identifier. The value wxID_ANY indicates a default value.
        @param value
            Initial selection string. An empty string indicates no selection.
        @param pos
            Window position.
        @param size
            Window size. If wxDefaultSize is specified then the window is
        sized
            appropriately.
        @param n
            Number of strings with which to initialise the control.
        @param choices
            An array of strings with which to initialise the control.
        @param style
            Window style. See wxBitmapComboBox.
        @param validator
            Window validator.
        @param name
            Window name.
        
        @see Create(), wxValidator
    */
    wxBitmapComboBox();
    wxBitmapComboBox(wxWindow* parent, wxWindowID id,
                     const wxString& value = "",
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     int n = 0,
                     const wxString choices[] = NULL,
                     long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = "comboBox");
    wxBitmapComboBox(wxWindow* parent, wxWindowID id,
                     const wxString& value,
                     const wxPoint& pos,
                     const wxSize& size,
                     const wxArrayString& choices,
                     long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = "comboBox");
    //@}

    /**
        Destructor, destroying the combobox.
    */
    ~wxBitmapComboBox();

    //@{
    /**
        Adds the item to the end of the combo box, associating the given, typed or
        untyped, client data pointer with the item.
    */
    int Append(const wxString& item,
               const wxBitmap& bitmap = wxNullBitmap);
    int Append(const wxString& item, const wxBitmap& bitmap,
               void* clientData);
    int Append(const wxString& item, const wxBitmap& bitmap,
               wxClientData* clientData);
    //@}

    //@{
    /**
        Creates the combobox for two-step construction. Derived classes
        should call or replace this function. See wxBitmapComboBox()
        for further details.
    */
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& value = "",
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n, const wxString choices[],
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "comboBox");
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "comboBox");
    //@}

    /**
        Returns size of bitmaps used in the list.
    */
    wxSize GetBitmapSize() const;

    /**
        Returns the bitmap of the item with the given index.
    */
    wxBitmap GetItemBitmap(unsigned int n) const;

    //@{
    /**
        Inserts the item into the list before pos, associating the given, typed or
        untyped, client data pointer with the item.
        Not valid for @c wxCB_SORT style, use Append instead.
    */
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos);
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos,
               void* clientData);
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos,
               wxClientData* clientData);
    //@}

    /**
        Sets the bitmap for the given item.
    */
    void SetItemBitmap(unsigned int n, const wxBitmap& bitmap);
};
