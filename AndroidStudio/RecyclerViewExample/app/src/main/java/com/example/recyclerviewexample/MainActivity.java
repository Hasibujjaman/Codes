package com.example.recyclerviewexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.Dialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    RecyclerView recyclerView1;
    RecyclerViewAdapter adapter1;
    FloatingActionButton btn1;
    ArrayList<ContactModel> arrListContact = new ArrayList<>();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView1 = findViewById(R.id.recyclerView1);
        btn1 = findViewById(R.id.btn1);

        //creating arraylist to use in Rycyclerview adapter
        arrListContact.add(new ContactModel(R.drawable.a,"A","000000001"));
        arrListContact.add(new ContactModel(R.drawable.b,"B","000000002"));
        arrListContact.add(new ContactModel(R.drawable.c,"C","000000003"));
        arrListContact.add(new ContactModel(R.drawable.d,"D","000000004"));
        arrListContact.add(new ContactModel(R.drawable.e,"E","000000005"));
        arrListContact.add(new ContactModel(R.drawable.f,"F","000000006"));
        arrListContact.add(new ContactModel(R.drawable.i,"I","000000007"));
        arrListContact.add(new ContactModel(R.drawable.j,"J","000000008"));
        arrListContact.add(new ContactModel(R.drawable.k,"K","000000009"));
        arrListContact.add(new ContactModel(R.drawable.a,"A","000000001"));
        arrListContact.add(new ContactModel(R.drawable.b,"B","000000002"));
        arrListContact.add(new ContactModel(R.drawable.c,"C","000000003"));
        arrListContact.add(new ContactModel(R.drawable.d,"D","000000004"));
        arrListContact.add(new ContactModel(R.drawable.e,"E","000000005"));
        arrListContact.add(new ContactModel(R.drawable.f,"F","000000006"));
        arrListContact.add(new ContactModel(R.drawable.i,"I","000000007"));
        arrListContact.add(new ContactModel(R.drawable.j,"J","000000008"));
        arrListContact.add(new ContactModel(R.drawable.k,"K","000000009"));

        //setting views on recyclerview by recyclerview adapter
        adapter1 = new RecyclerViewAdapter(MainActivity.this, arrListContact);
        recyclerView1.setAdapter(adapter1);
        recyclerView1.setLayoutManager(new LinearLayoutManager(MainActivity.this));


        //Adding new rows to recyclerview
        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Dialog dialog = new Dialog(MainActivity.this);
                dialog.setContentView(R.layout.add_update);
                dialog.show();

                EditText edtName = dialog.findViewById(R.id.edtName);
                EditText edtNumber = dialog.findViewById(R.id.edtNumber);
                Button btnAction = dialog.findViewById(R.id.btnAdd);


                btnAction.setOnClickListener(new View.OnClickListener() {

                    @Override
                    public void onClick(View view) {
                        String name = "", number = "";
                        if(!edtName.getText().toString().equals("") && !edtNumber.getText().toString().equals("")){
                            name = edtName.getText().toString();
                            number = edtNumber.getText().toString();

                            arrListContact.add(new ContactModel(name,number)); // new data is added in arraylist
                            adapter1.notifyItemInserted(arrListContact.size()-1); // RV is also updated
                            //adapter1.notifyDataSetChanged();
                            recyclerView1.scrollToPosition(arrListContact.size()-1);

                            dialog.dismiss();
                            Toast.makeText(MainActivity.this,"New contact has been added",Toast.LENGTH_SHORT).show();

                        }
                        else
                            Toast.makeText(MainActivity.this,"Enter name and number first",Toast.LENGTH_SHORT).show();

                    }
                });


            }
        });

    }


}