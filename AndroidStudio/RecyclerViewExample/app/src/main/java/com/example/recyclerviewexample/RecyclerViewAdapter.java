package com.example.recyclerviewexample;


import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import java.util.ArrayList;

public class RecyclerViewAdapter  extends RecyclerView.Adapter<RecyclerViewAdapter.ViewHolder>{

    public static class ViewHolder extends RecyclerView.ViewHolder{

        TextView txtView1,txtView2;
        ImageView imgView1;
        LinearLayout llRow;
        public ViewHolder(View itemView){
            super(itemView);
            txtView1 = itemView.findViewById(R.id.txtView1);
            txtView2 = itemView.findViewById(R.id.txtView2);
            imgView1 = itemView.findViewById(R.id.imgView1);
            llRow = itemView.findViewById(R.id.llRow);


        }

    }

    Context context1;
    ArrayList<ContactModel> arrList1;
    RecyclerViewAdapter(Context context, ArrayList<ContactModel> arrList){
        context1 = context;
        arrList1 = arrList;
    }



    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view1 = LayoutInflater.from(context1).inflate(R.layout.contact_row,parent,false);
        return new ViewHolder(view1);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.txtView1.setText(arrList1.get(position).name);
        holder.txtView2.setText(arrList1.get(position).number);
        holder.imgView1.setImageResource(arrList1.get(position).img);

        //Edit recycler view item
        holder.llRow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Dialog dialog = new Dialog(context1);
                dialog.setContentView(R.layout.add_update);
                dialog.show();

                TextView txtTitle = dialog.findViewById(R.id.txtTitle);
                EditText edtName = dialog.findViewById(R.id.edtName);
                EditText edtNumber = dialog.findViewById(R.id.edtNumber);
                Button btnAction = dialog.findViewById(R.id.btnAdd);

                txtTitle.setText("Edit Contact");
                btnAction.setText("Update");
                edtName.setText(arrList1.get(holder.getAdapterPosition()).name);
                edtNumber.setText(arrList1.get(holder.getAdapterPosition()).number);

                btnAction.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        String name = "", number = "";
                        if(!edtName.getText().toString().equals("") && !edtNumber.getText().toString().equals("")){
                            name = edtName.getText().toString();
                            number = edtNumber.getText().toString();
                            arrList1.set(holder.getAdapterPosition(),new ContactModel(arrList1.get(holder.getAdapterPosition()).img,name,number));
                            notifyItemChanged(holder.getAdapterPosition());
                            dialog.dismiss();
                            Toast.makeText(context1,"Contact has been updated",Toast.LENGTH_SHORT).show();

                        }
                        else
                            Toast.makeText(context1,"Invalid name or number",Toast.LENGTH_SHORT).show();


                    }
                });

            }
        });
        //Delete recycler view item
        holder.llRow.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(context1)
                        .setTitle("Delete Contact")
                        .setMessage("Selected contact will be deleted")
                        .setIcon(R.drawable.baseline_delete_24)
                        .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                arrList1.remove(holder.getAdapterPosition());
                                notifyItemRemoved(holder.getAdapterPosition());

                            }
                        })
                        .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                            }
                        });
                builder.show();

                return true;
            }
        });

    }

    @Override
    public int getItemCount() {
        return arrList1.size();
    }




}
