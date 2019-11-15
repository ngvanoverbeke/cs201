var dropboxPicker = {};

/**
 * The Dropbox Picker object controls the behavior of the Dropbox Chooser widget within the filePicker tag. This picker will notify the
 * Dropbox Integration B2 of any Dropbox files selected by the user and will to save them within the Content System's private document store
 * for the current session.
 */
dropboxPicker.DisplayController = Class.create();
dropboxPicker.DisplayController.prototype =
{
  initialize: function( baseElementName, appKey, courseId, multiselectEnabled )
  {
    this.appKey = appKey;
    this.baseElementName = baseElementName;
    this.courseId = courseId;
    this.multiselectEnabled = multiselectEnabled;
  },

  getOptions: function()
  {
    this.initDropbox();
    var self = this;
    var options =
    {
      // Required. Called when a user selects an item in the Chooser.
      success: function( files )
      {
        self.processDropboxItems( files, self.courseId );
      },

      // Optional. "preview" (default) is a preview link to the document for sharing,
      // "direct" is an expiring link to download the contents of the file. For more
      // information about link types, see Link types below.
      linkType: "direct",

      // Optional. A value of false (default) limits selection to a single file, while
      // true enables multiple file selection.
      multiselect: self.multiselectEnabled
    };
    return options;
  },

  processDropboxItems: function( files )
  {
    var self = this;
    new Ajax.Request( '/webapps/dropbox-integration/api/v1/files?course_id=' + self.courseId, {
      method: 'post',
      contentType: 'application/json',
      postBody: JSON.stringify( files ),
      onLoading: function()
      {
        self.toggleLoading( true );
      },
      onSuccess: function( transport )
      {
        var response = transport.responseText.evalJSON( true );
        self.addFilesToPicker( response );
      },
      onFailure: function()
      {
        alert( page.bundle.getString( "filePicker.dropbox.error.unknown" ) );
      },
      onComplete: function()
      {
        self.toggleLoading( false );
      }
    });
  },

  addFilesToPicker: function( processedFiles )
  {
    var filePicker = widget.FilePicker.getFilePicker( this.baseElementName );
    if ( !this.multiselectEnabled && processedFiles[0] )
    {
      filePicker.selectedCSFile.value = processedFiles[0].fileName;
      filePicker.selectedCSFileSize.value = processedFiles[0].size;
      filePicker.selectedCSFileName.value = processedFiles[0].linkTitle;
      if ( processedFiles[0].fileName )
      {
        filePicker.selectedCSFilePath.value = processedFiles[0].fileName;
      }
    }
    return filePicker.onCSPick( processedFiles );
  },

  toggleLoading: function( visible )
  {
    if ( this.multiselectEnabled )
    {
      var listHtmlDiv = $( this.baseElementName + "_listHtmlDiv" );
      var tableBody = $( this.baseElementName + "_table_body" );
      if ( listHtmlDiv )
      {
        listHtmlDiv.show();
        $( this.baseElementName + "_loading" ).toggle( visible );
        if ( !visible && tableBody.getElementsByTagName( 'tr' ).length == 0 )
        {
          listHtmlDiv.hide();
        }
      }
    }
    else
    {
      $( this.baseElementName + "_loading" ).toggle( visible );
    }
  },

  initDropbox: function()
  {
    if ( !Dropbox.appKey )
    {
      Dropbox.appKey = this.appKey;
    }
  }
};