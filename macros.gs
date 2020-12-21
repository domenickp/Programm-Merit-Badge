function onOpen() {   // This is a special function that runs every time the spreadsheet is opened.
  var ui = SpreadsheetApp.getUi();
  showAlert(); // Pop up the confirmation dialog by running this function.
}

function showAlert() {
  var ui = SpreadsheetApp.getUi();

  var result = ui.alert(
     'Merit Bagde Macros!',
     'I am about to create the Merit Badge Menu!',
      ui.ButtonSet.OK_CANCEL);

  // Process the user's response.
  if (result == ui.Button.OK) {
    // User clicked "OK".
    ui.createMenu('Merit Badge Menu')
    .addItem('Set Title Row and Sort Data', 'TitleAndSort')
    .addToUi();
    ui.alert('Menu added!');
  } else {
    // User clicked "Cancel" or X in the title bar.
    ui.alert('Not making the menu!');
  }
}

function TitleAndSort() {
  var spreadsheet = SpreadsheetApp.getActive();
  spreadsheet.getRange('1:1').activate();
  spreadsheet.getActiveSheet().setFrozenRows(1);
  spreadsheet.getRange('C2').activate();
  spreadsheet.getActiveSheet().sort(3, true);
};

