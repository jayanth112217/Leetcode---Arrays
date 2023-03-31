 int max(int a,int b){
   if(a<b)
    return b;
   return a;
 }
 int min(int a,int b){
   if(a<b)
     return a;
   return b;
 }
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **result = malloc(sizeof(int *) * (intervalsSize + 1)); 
  *returnSize=0;
  if(intervalsSize==0 && newIntervalSize!=0){
    result[*returnSize] = malloc(sizeof(int) * 2);
    result[*returnSize][0] = newInterval[0];
    result[*returnSize][1] = newInterval[1];
    (*returnSize)++;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = 2;
    return result;    
  }
    int index=0;
    for(int i=0;i<intervalsSize;i++){
        if(intervals[i][0]>newInterval[0] && i>0){
            index=i-1;
            break;
        }
    }
      if(index==0 && intervals[0][0]>newInterval[1]){
      result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = newInterval[0];
       result[*returnSize][1] = newInterval[1];
       (*returnSize)++;
     for(int j=0;j<intervalsSize;j++){
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[j][0];
       result[*returnSize][1] = intervals[j][1];
       (*returnSize)++;
     }
     *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
        return result;      
    }
    else if(index==0 && newInterval[0]>intervals[intervalsSize-1][1]){
       for(int j=0;j<intervalsSize;j++){
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[j][0];
       result[*returnSize][1] = intervals[j][1];
       (*returnSize)++;
       }
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = newInterval[0];
       result[*returnSize][1] = newInterval[1];
       (*returnSize)++;
        *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
        return result;
    }
    int start = newInterval[0];
    int end = newInterval[1];
    int prime=0;
    for(int i=0;i<intervalsSize;i++){
     if(i>=index && intervals[i][0]<=end && intervals[i][1]>=start){
       start = min(intervals[i][0],start);
       end = max(intervals[i][1],end);
       if(i == intervalsSize-1 || intervals[i+1][0]>end){
        result[*returnSize] = malloc(sizeof(int) * 2);
        result[*returnSize][0] = start;
        result[*returnSize][1] = end;
        (*returnSize)++;
        prime=1;
        continue;    
       }       
     }
     else{
      if(intervalsSize==1){
       if(newInterval[0]<intervals[i][0]){
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = newInterval[0];
       result[*returnSize][1] = newInterval[1];
       (*returnSize)++;  
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[i][0];
       result[*returnSize][1] = intervals[i][1];
       (*returnSize)++;
       *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
        return result;    
       }
       else{
          result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[i][0];
       result[*returnSize][1] = intervals[i][1];
       (*returnSize)++;
         result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = newInterval[0];
       result[*returnSize][1] = newInterval[1];
       (*returnSize)++;  
       *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
        return result; 
       }
      }
     else if(i<=index || prime==1){
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[i][0];
       result[*returnSize][1] = intervals[i][1];
       (*returnSize)++;
     }
     else{
        if(intervals[i][0]>newInterval[1]){
        result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = newInterval[0];
       result[*returnSize][1] = newInterval[1];
       (*returnSize)++;  
        for(int p=i;p<intervalsSize;p++){
          result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[p][0];
       result[*returnSize][1] = intervals[p][1];
       (*returnSize)++;
        }
        *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
        return result; 
        }
       result[*returnSize] = malloc(sizeof(int) * 2);
       result[*returnSize][0] = intervals[i][0];
       result[*returnSize][1] = intervals[i][1];
       (*returnSize)++;   
     }
     } 
    }
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = 2;
    return result;    
}