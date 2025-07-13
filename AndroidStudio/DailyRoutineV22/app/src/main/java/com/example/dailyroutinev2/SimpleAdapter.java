package com.example.dailyroutinev2;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class SimpleAdapter extends BaseAdapter{
    private Context context;
    private LayoutInflater layoutInflater;
    private ImageView imgDes;
    private TextView txtTitle, txtTime, txtAI;
    private String[] titleArr;
    private String[] timeArr;
    private String[] aiArr;

    public SimpleAdapter(Context context, String[] titleArr, String[] timeArr, String[] aiArr) {
        this.context = context;
        this.titleArr = titleArr;
        this.timeArr = timeArr;
        this.aiArr = aiArr;
        layoutInflater = LayoutInflater.from(context);
    }
    public SimpleAdapter(Context context, String[] titleArr) {
        this.context = context;
        this.titleArr = titleArr;
        layoutInflater = LayoutInflater.from(context);
    }


    @Override
    public int getCount() {
        return titleArr.length;
    }

    @Override
    public Object getItem(int position) {
        return titleArr[position];
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View view, ViewGroup viewGroup) {
        if(view == null){
            view = layoutInflater.inflate(R.layout.item_model,null);
        }

        imgDes = view.findViewById(R.id.imgDes);
        txtTitle = view.findViewById(R.id.txtTask);
        txtTime = view.findViewById(R.id.txtTime);
        txtAI = view.findViewById(R.id.txtAI);
        if(titleArr != null)
            txtTitle.setText(titleArr[position]);
        if(timeArr != null)
            txtTime.setText(timeArr[position]);
        if(aiArr != null)
            txtAI.setText(aiArr[position]);


        if(titleArr[position].equalsIgnoreCase("Saturday")){
            imgDes.setImageResource(R.drawable.sat);
        }
        if(titleArr[position].equalsIgnoreCase("Sunday")){
            imgDes.setImageResource(R.drawable.sun);
        }
        if(titleArr[position].equalsIgnoreCase("Monday")) {
            imgDes.setImageResource(R.drawable.mon);
        }
        if(titleArr[position].equalsIgnoreCase("Tuesday")){
            imgDes.setImageResource(R.drawable.tue);
        }
        if(titleArr[position].equalsIgnoreCase("Wednesday")){
            imgDes.setImageResource(R.drawable.wed);
        }
        if(titleArr[position].equalsIgnoreCase("Thursday")){
            imgDes.setImageResource(R.drawable.thu);
        }
        if(titleArr[position].equalsIgnoreCase("Friday")){
            imgDes.setImageResource(R.drawable.fri);
        }

        return  view;
    }
}
