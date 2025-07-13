package com.example.fragmentexample3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button btnLoadFragA, btnLoadFragB;
    EditText edtMain;
    TextView txtMain;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnLoadFragA = findViewById(R.id.btnLoadFragA);
        btnLoadFragB = findViewById(R.id.btnLoadFragB);
        edtMain = findViewById(R.id.edtMain);
        txtMain = findViewById(R.id.txtMain);

        //Receiving data from from fragment B (method 1)
        Intent intent = getIntent();
        String data = intent.getStringExtra("dfB");
        txtMain.setText(data);

        //Loading Fragment A as default with data sent from main activity to Fragment A via method 2
        loadFragment(FragmentA.getInstance("Default Value"), false, 1);

        btnLoadFragA.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                loadFragment(new FragmentA(), true,1);
                Toast.makeText(MainActivity.this,"Fragment A loaded",Toast.LENGTH_SHORT).show();



            }
        });
        btnLoadFragB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                loadFragment(new FragmentB(), true, 2);
                Toast.makeText(MainActivity.this,"Fragment B loaded",Toast.LENGTH_SHORT).show();




            }
        });





    }

    public void loadFragment(Fragment fragment, boolean is_loaded, int frag_mark){
        FragmentManager fm = getSupportFragmentManager();
        FragmentTransaction ft = fm.beginTransaction();

        if(is_loaded)
            ft.replace(R.id.fragContainer,fragment);
        else
            ft.add(R.id.fragContainer,fragment);

        ft.commit();

        //sending data from main activity to Fragment A (Method 1)
        if(frag_mark == 1){
            Bundle bundle = new Bundle();
            if(!edtMain.getText().toString().equals("")){
                String data1 = edtMain.getText().toString();
                bundle.putString("key1",data1);
                fragment.setArguments(bundle);
            }
        }
        //Sending data from Fragment A to Fragment B
        if(frag_mark == 2){



        }
    }

    public void setTxtMain(String dataFromFragB){

        txtMain.setText(dataFromFragB);
    }
}