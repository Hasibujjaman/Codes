package com.example.recyclerviewexample;

public class ContactModel {
    int img;
    String name, number;

    public ContactModel(int img, String name, String number){
        this.img = img;
        this.name = name;
        this.number = number;
    }

    public ContactModel(String name, String number){
        this.name = name;
        this.number = number;
    }

}



//btn1.setOnClickListener(new View.OnClickListener() {
//@Override
//public void onClick(View view) {
//
//        Dialog dialog = new Dialog(MainActivity.this);
//        dialog.setContentView(R.layout.add_update);
//
//        EditText edtName = dialog.findViewById(R.id.edtName);
//        EditText edtNumber = dialog.findViewById(R.id.edtNumber);
//        Button btnAction = dialog.findViewById(R.id.btn1);
//
//        btnAction.setOnClickListener(new View.OnClickListener() {
//@Override
//public void onClick(View view) {
//        String name = "", number = "";
//        if(!edtName.getText().toString().equals("")){
//        name = edtName.getText().toString();
//        }
//        else
//        Toast.makeText(MainActivity.this,"Please enter contact name",Toast.LENGTH_SHORT).show();
//        if(!edtNumber.getText().toString().equals("")){
//        number = edtNumber.getText().toString();
//        }
//        else
//        Toast.makeText(MainActivity.this,"Please enter contact number",Toast.LENGTH_SHORT).show();
//
//        arrListContact.add(new ContactModel(name,number));
//        adapter1.notifyItemInserted(arrListContact.size()-1);
//        recyclerView1.scrollToPosition(arrListContact.size()-1);
//
//        }
//        });
//
//        dialog.show();
//
//        }
//        });