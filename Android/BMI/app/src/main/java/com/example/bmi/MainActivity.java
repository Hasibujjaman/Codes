package com.example.bmi;

import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        EditText edtHeightFt,edtHeightIn,edtWeight;
        Button btncalc;
        TextView txtResult;
        LinearLayout llHome;

        edtHeightFt = findViewById(R.id.edtHF);
        edtHeightIn = findViewById(R.id.edtHI);
        edtWeight = findViewById(R.id.edtW);
        btncalc = findViewById(R.id.btnC);
        txtResult = findViewById(R.id.txtR);
        llHome = findViewById(R.id.llHome);


        View.OnClickListener onClickListener = new View.OnClickListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onClick(View view) {
                try {
                    int heightF = Integer.parseInt(edtHeightFt.getText().toString());
                    int heightI = Integer.parseInt(edtHeightIn.getText().toString());
                    int weight = Integer.parseInt(edtWeight.getText().toString());

                    double totalH = ((heightI + 12 * heightF) * 2.54) / 100;
                    double bmi = weight / (totalH * totalH);

                    if (bmi > 25) {
                        txtResult.setText("You are Overweight");
                        llHome.setBackgroundColor(getResources().getColor(R.color.Red));
                    } else if (bmi < 18) {
                        txtResult.setText("You are Underweight");
                        llHome.setBackgroundColor(getResources().getColor(R.color.Yellow));
                    } else {
                        txtResult.setText("You are Healthy");
                        llHome.setBackgroundColor(getResources().getColor(R.color.Green));
                    }
                }
                catch (NumberFormatException e){
                    txtResult.setText("Enter all the values first");
                    llHome.setBackgroundColor(getResources().getColor(R.color.Error));
                }
            }
        };

        btncalc.setOnClickListener(onClickListener);
    }

}