package com.example.roomlibraryexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    EditText edtName, edtAmount;
    Button btnAdd,btnDel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtName = findViewById(R.id.edtTitle);
        edtAmount = findViewById(R.id.edtAmount);
        btnAdd = findViewById(R.id.btnAdd);
        btnDel = findViewById(R.id.btnDel);

        //creating DB
        DBHelper dbHelper = DBHelper.getDB(this);
        Context context = MainActivity.this;


        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(!edtName.getText().toString().equals("") && !edtAmount.getText().toString().equals("")){
                    String title = edtName.getText().toString();
                    String amount = edtAmount.getText().toString();
                    //inserting data to DB
                    dbHelper.expenseDAO().insertTxn(new Expense(title, amount));

                    edtName.setText("");
                    edtAmount.setText("");
                }
                //fetching data from DB
                ArrayList<Expense> allExpense = (ArrayList<Expense>) dbHelper.expenseDAO(). getAllExpense();
                for(int i = 0; i < allExpense.size(); i++){
                    Log.d("DB1, Expense_Table","Id : " + allExpense.get(i).getId() + " Name : "
                                                                + allExpense.get(i).getTitle() + " Amount : "
                                                                + allExpense.get(i).getAmount());
                }

            }

        });

        btnDel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                dbHelper.clearAllTables();
            }
        });



    }
}